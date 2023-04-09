input [3:0] numeral_bit;

output c;

wire not_numeral_bit_3;
wire not_numeral_bit_2;
wire not_numeral_bit_1;
wire not_numeral_bit_0;

wire not_3_and_not_2;
wire not_1_and_not_0;
wire not_1_and_0;
wire 1_and_0;
wire not_3_and_2;
wire 1_and_not_0;
wire 3_and_not_2;

wire maxterm_00;
wire maxterm_01;
wire maxterm_03;
wire maxterm_04;
wire maxterm_05;
wire maxterm_06;
wire maxterm_07;
wire maxterm_08;
wire maxterm_09;

wire maxterm_00_or_maxterm_01;
wire maxterm_03_or_maxterm_04;
wire maxterm_05_or_maxterm_06;
wire maxterm_07_or_maxterm_08;

wire 00_01_or_03_04;
wire 05_06_or_07_08;
wire maxterm_temp;

assign not_numeral_bit_3 = ~ numeral_bit[3];
assign not_numeral_bit_2 = ~ numeral_bit[2];
assign not_numeral_bit_1 = ~ numeral_bit[1];
assign not_numeral_bit_0 = ~ numeral_bit[0];

assign not_3_and_not_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_1_and_not_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign not_1_and_0 = not_numeral_bit_1 & numeral_bit[0];
assign 1_and_0 = numeral_bit[1] & numeral_bit[0];
assign not_3_and_2 = not_numeral_bit_3 & numeral_bit[2];
assign 1_and_not_0 = numeral_bit[1] & not_numeral_bit_0;
assign 3_and_not_2 = numeral_bit[3] & not_numeral_bit_2;

assign maxterm_00 = not_3_and_not_2 & not_1_and_not_0;
assign maxterm_01 = not_3_and_not_2 & not_1_and_0;
assign maxterm_03 = not_3_and_not_2 & 1_and_0;
assign maxterm_04 = not_3_and_2 & not_1_and_not_0;
assign maxterm_05 = not_3_and_2 & not_1_and_0;
assign maxterm_06 = not_3_and_2 & 1_and_not_0;
assign maxterm_07 = not_3_and_2 & 1_and_0;
assign maxterm_08 = 3_and_not_2 & not_1_and_not_0;
assign maxterm_09 = 3_and_not_2 & not_1_and_0;

assign maxterm_00_or_maxterm_01 = maxterm_00 | maxterm_01 ;
assign maxterm_03_or_maxterm_04 = maxterm_03 | maxterm_04;
assign maxterm_05_or_maxterm_06 = maxterm_05 | maxterm_06 ;
assign maxterm_07_or_maxterm_08 = maxterm_07 | maxterm_08;

assign 00_01_or_03_04 = maxterm_00_or_maxterm_01 | maxterm_03_or_maxterm_04;
assign 05_06_or_07_08 = maxterm_05_or_maxterm_06 | maxterm_07_or_maxterm_08;
assign maxterm_temp = 00_01_or_03_04 | 05_06_or_07_08;

assign c = maxterm_temp | maxterm_09;
