<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CLOCK_XMC1" URI="http://resources/4.0.6/app/CLOCK_XMC1/0" description="APP to configure System and Peripheral Clocks." version="4.0.6" minDaveVersion="4.0.0" instanceLabel="CLOCK_XMC1_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../GLOBAL_CCU4/v4_1_4/GLOBAL_CCU4_0.app#//@requiredApps.0"/>
  <properties singleton="true" sharable="true"/>
  <virtualSignals name="clk_dco2_output" URI="http://resources/4.0.6/app/CLOCK_XMC1/0/vs_dco_clkout" hwSignal="clkout" hwResource="//@hwResources.0"/>
  <virtualSignals name="clk_rtc" URI="http://resources/4.0.6/app/CLOCK_XMC1/0/vs_frtc" hwSignal="frtc" hwResource="//@hwResources.1"/>
  <hwResources name="DCO CLOCK" URI="http://resources/4.0.6/app/CLOCK_XMC1/0/hwres_dco" resourceGroupUri="peripheral/scu/0/dco/*" mResGrpUri="peripheral/scu/0/dco/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU/SCU_0.dd#//@provided.0"/>
  </hwResources>
  <hwResources name="CLOCK CONTROL UNIT" URI="http://resources/4.0.6/app/CLOCK_XMC1/0/hwres_clkcntrlunit" resourceGroupUri="peripheral/scu/0/ccu/config" mResGrpUri="peripheral/scu/0/ccu/config">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/SCU/SCU_0.dd#//@provided.1"/>
  </hwResources>
  <connections URI="http://resources/4.0.6/app/CLOCK_XMC1/0/http://resources/4.0.6/app/CLOCK_XMC1/0/vs_dco_clkout/http://resources/4.0.6/app/CLOCK_XMC1/0/vs_frtc" systemDefined="true" sourceSignal="clk_dco2_output" targetSignal="clk_rtc" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.1"/>
</ResourceModel:App>
