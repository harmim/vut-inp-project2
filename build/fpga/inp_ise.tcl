#============================================================================
# Run: 
#    xtclsh inp_ise.tcl  - creates XILINX ISE project file
#    ise inp_project.ise - opens the project
#============================================================================
source "../../../../../base/xilinxise.tcl"

project_new "inp_project"
project_set_props
puts "Adding source files"
xfile add "../../../../../fpga/units/clkgen/clkgen_config.vhd"
xfile add "inp_config.vhd"
xfile add "../../../../../fpga/units/clkgen/clkgen.vhd"
xfile add "../../../../../fpga/units/math/math_pack.vhd"
xfile add "../../../../../fpga/ctrls/spi/spi_adc_entity.vhd"
xfile add "../../../../../fpga/ctrls/spi/spi_adc.vhd"
xfile add "../../../../../fpga/ctrls/spi/spi_adc_autoincr.vhd"
xfile add "../../../../../fpga/ctrls/spi/spi_reg.vhd"
xfile add "../../../../../fpga/ctrls/spi/spi_ctrl.vhd"
xfile add "../../../../../fpga/chips/fpga_xc3s50.vhd"
xfile add "../../../../../fpga/chips/architecture_bare/arch_bare_ifc.vhd"
xfile add "../../../../../fpga/chips/architecture_bare/tlv_bare_ifc.vhd"
xfile add "../../../../../fpga/ctrls/keyboard/keyboard_ctrl.vhd"
xfile add "../../../../../fpga/ctrls/keyboard/keyboard_ctrl_high.vhd"
xfile add "../../fpga/lcdctrl.vhd"
xfile add "../../fpga/kbctrl.vhd"
xfile add "../../fpga/ram.vhd"
xfile add "../../fpga/rom.vhd"
xfile add "../../fpga/cpu.vhd"
xfile add "../../fpga/top.vhd"
puts "Adding simulation files"
xfile add "../../fpga/sim/tb.vhd" -view Simulation
xfile add "../../../../../fpga/models/keyboard/keyboard.vhd" -view Simulation
xfile add "../../../../../fpga/models/lcd/lcd.vhd" -view Simulation
xfile add "../../fpga/sim/tb.vhd" -view Simulation
puts "Libraries"
project_set_isimscript "inp_xsim.tcl"
project_set_top "fpga"
project_close
