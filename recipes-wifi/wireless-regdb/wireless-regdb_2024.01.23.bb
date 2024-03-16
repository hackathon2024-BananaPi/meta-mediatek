SUMMARY = "Wireless Central Regulatory Domain Database"
HOMEPAGE = "https://wireless.wiki.kernel.org/en/developers/regulatory/crda"
SECTION = "net"
LICENSE = "ISC"
LIC_FILES_CHKSUM = "file://LICENSE;md5=07c4f6dea3845b02a18dc00c8c87699c"

SRC_URI = "https://www.kernel.org/pub/software/network/${BPN}/${BP}.tar.xz"
SRC_URI[sha256sum] = "c8a61c9acf76fa7eb4239e89f640dee3e87098d9f69b4d3518c9c60fc6d20c55"

FILESEXTRAPATHS_prepend := "${THISDIR}/files/patches:"
require files/patches/patches.inc

inherit bin_package allarch ${@bb.utils.contains("DISTRO_FEATURES", "kirkstone", "python3native", "pythonnative", d)}

S = "${WORKDIR}/${PN}-${PV}"

do_install_prepend() {
    (python ${S}/db2fw.py ${S}/regulatory.db ${S}/db.txt)
}

do_install() {
    install -d -m0755 ${D}${nonarch_libdir}/crda
    install -d -m0755 ${D}${sysconfdir}/wireless-regdb/pubkeys
    install -m 0644 regulatory.bin ${D}${nonarch_libdir}/crda/regulatory.bin
    install -m 0644 wens.key.pub.pem ${D}${sysconfdir}/wireless-regdb/pubkeys/wens.key.pub.pem

    install -m 0644 -D regulatory.db ${D}${nonarch_base_libdir}/firmware/regulatory.db
    install -m 0644 regulatory.db.p7s ${D}${nonarch_base_libdir}/firmware/regulatory.db.p7s
}

# Install static regulatory DB in /lib/firmware for kernel to load.
# This requires Linux kernel >= v4.15.
# For kernel <= v4.14, inherit the kernel_wireless_regdb.bbclass
# (in meta-networking) in kernel's recipe.
PACKAGES = "${PN}-static ${PN}"
RCONFLICTS:${PN} = "${PN}-static"

FILES:${PN}-static = " \
    ${nonarch_base_libdir}/firmware/regulatory.db \
    ${nonarch_base_libdir}/firmware/regulatory.db.p7s \
"

# Native users might want to use the source of regulatory DB.
# This is for example used by Linux kernel <= v4.14 and
# kernel_wireless_regdb.bbclass in meta-networking.
do_install:append:class-native() {
    install -m 0644 -D db.txt ${D}${libdir}/crda/db.txt
}

RSUGGESTS:${PN} = "crda"

BBCLASSEXTEND = "native"
