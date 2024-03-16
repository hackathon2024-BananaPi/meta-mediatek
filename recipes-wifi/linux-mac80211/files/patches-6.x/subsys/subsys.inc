#patch subsys (come from openwrt/lede/target/linux/mediatek)
SRC_URI_append = " \
    file://001-wifi-mac80211-do-not-pass-ap_vlan-vif-pointer-to-dri.patch \
    file://110-mac80211_keep_keys_on_stop_ap.patch \
    file://120-cfg80211_allow_perm_addr_change.patch \
    file://130-disable_auto_vif.patch \
    file://210-ap_scan.patch \
    file://301-mac80211-sta-randomize-BA-session-dialog-token-alloc.patch \
    file://302-mac80211-minstrel_ht-fix-MINSTREL_FRAC-macro.patch \
    file://303-mac80211-minstrel_ht-reduce-fluctuations-in-rate-pro.patch \
    file://304-mac80211-minstrel_ht-rework-rate-downgrade-code-and-.patch \
    file://305-mac80211-increase-quantum-for-airtime-scheduler.patch \
    file://310-mac80211-split-mesh-fast-tx-cache-into-local-proxied.patch \
    file://311-mac80211-fix-mesh-id-corruption-on-32-bit-systems.patch \
    file://312-wifi-cfg80211-annotate-iftype_data-pointer-with-spar.patch \
    file://313-wifi-cfg80211-export-DFS-CAC-time-and-usable-state-h.patch \
    file://314-wifi-mac80211-fix-race-condition-on-enabling-fast-xm.patch \
    file://320-cfg80211-allow-grace-period-for-DFS-available-after-.patch \
    file://400-allow-ibss-mixed.patch \
    file://780-avoid-crashing-missing-band.patch \
    file://782-net-next-1-of-net-pass-the-dst-buffer-to-of_get_mac_address.patch \
    file://bp-0001-backports-Revert-mac80211-use-the-new-drop-reasons-i.patch \
    file://bp-0002-backports-update-kernel-version-check-for-eth_hw_add.patch \
    file://bp-0003-backports-Revert-cfg80211-allow-grace-period-for-DFS.patch \
    file://mtk-0001-mtk-mac80211-do-not-setup-twt-when-twt-responder-is-.patch \
    file://mtk-0002-mtk-cfg80211-extend-CAC-time-for-weather-radar-chann.patch \
    file://mtk-0003-mtk-mac80211-it-s-invalid-case-when-frag_threshold-i.patch \
    file://mtk-0004-mtk-mac80211-add-support-for-runtime-set-inband-disc.patch \
    file://mtk-0005-mtk-cfg80211-implement-DFS-status-show-cac-and-nop-s.patch \
    file://mtk-0006-mtk-mac80211-Set-TWT-Information-Frame-Disabled-bit-.patch \
    file://mtk-0007-mtk-mac80211-check-the-control-channel-before-downgr.patch \
    file://mtk-0008-mtk-mac80211-fix-tx-amsdu-aggregation.patch \
    file://mtk-0009-mtk-mac80211-add-fill-receive-path-ops-to-get-wed-id.patch \
    file://mtk-0010-mtk-mac80211-fix-build-error-on-Linux-Kernel-5.4.patch \
    file://mtk-0011-mtk-mac80211-track-obss-color-bitmap.patch \
    file://mtk-0012-mtk-mac80211-ageout-color-bitmap.patch \
    file://mtk-0013-mtk-mac80211-update-max_bssid_indicator-based-on-rea.patch \
    file://mtk-0014-mtk-mac80211-support-configurable-addba-resp-time.patch \
    file://mtk-0015-mtk-mac80211-add-sta-assisted-DFS-state-update-mecha.patch \
    file://mtk-0016-mtk-nl80211-Mark-DFS-channel-as-available-for-CSA.patch \
    file://mtk-0017-mtk-cfg80211-fix-early-return-in-cfg80211_stop_backg.patch \
    file://mtk-0018-mtk-cfg80211-add-background-radar-stop-when-backgrou.patch \
    file://mtk-0019-mtk-mac80211-avoid-kernel-warning-of-check_flush_dep.patch \
    file://mtk-0020-mtk-mac80211-avoid-calling-switch_vif_chanctx-when-u.patch \
    file://mtk-0021-mtk-mac80211-Add-utilities-for-converting-op_class.patch \
    file://mtk-0022-mtk-mac80211-refactor-STA-CSA-parsing-flows.patch \
    file://mtk-0023-mtk-mac80211-add-EHT-BA1024-support.patch \
    file://mtk-0024-mtk-mac80211-add-rate-duration-for-EHT-rate.patch \
    file://mtk-0025-mtk-mac80211-add-send-bar-action-when-recieve-addba-.patch \
    file://mtk-0026-mtk-mac80211-inrease-beacon-loss-count.patch \
    file://mtk-0027-mtk-cfg80211-add-support-for-updating-background-cha.patch \
    file://mtk-0028-mtk-mac80211-Allow-STA-interface-to-set-TX-queue-par.patch \
    file://mtk-0029-mtk-mac80211-export-ieee80211_tpt_led_trig_tx-rx-for.patch \
    file://mtk-0030-mtk-mac80211-add-packet-count-input-for-dev_sw_netst.patch \
    file://mtk-0031-mtk-mac80211-add-per-bss-flag-to-support-vendors-cou.patch \
    file://mtk-0032-mtk-mac80211-set-eht_support-to-false-when-AP-is-not.patch \
    file://mtk-0033-mtk-mac80211-Add-cert-mode-to-disable-ba-timeout.patch \
    file://mtk-0034-mtk-mac80211-Fix-he_6ghz_oper-NULL-pointer-access.patch \
    file://mtk-0035-mtk-mac80211-ACS-channel-time-is-reset-by-ch_restore.patch \
    file://mtk-0036-mtk-mac80211-Fix-SMPS-action-frame-cap-check.patch \
    file://mtk-0037-mtk-mac80211-Add-CSA-action-frame-tx-when-channel-sw.patch \
    "