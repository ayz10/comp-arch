input [3:0] numeral_bit;

output a;
output b;
output c;
output d;
output e;
output f;
output g;

wire not_numeral_bit_3;
wire not_numeral_bit_2;
wire not_numeral_bit_1;
wire not_numeral_bit_0;

wire not_3_and_not_2;
wire 3_and_not_2;
wire not_3_and_2;
wire not_1_and_not_0;
wire not_1_and_0;
wire 1_and_not_0;
wire 1_and_0;

wire minterm_00;
wire minterm_01;
wire minterm_02;
wire minterm_03;
wire minterm_04;
wire minterm_05;
wire minterm_06;
wire minterm_07;
wire minterm_08;
wire minterm_09;

wire 00_or_01;
wire 00_or_02;
wire 00_or_04;
wire 02_or_03;
wire 03_or_04;
wire 03_or_05;
wire 04_or_05;
wire 04_or_07;
wire 05_or_06;
wire 06_or_07;
wire 06_or_08;
wire 07_or_08;
wire 08_or_09;

wire 00_01_or_02_03;
wire 00_01_or_03_04;
wire 00_02_or_03_05;
wire 00_04_or_05_06;
wire 02_03_or_04_05;
wire 04_07_or_08_09;
wire 05_06_or_07_08;
wire 06_07_or_08_09;
wire 06_08_or_09;

wire minterm_temp;

assign not_numeral_bit_3 = ~ numeral_bit[3];
assign not_numeral_bit_2 = ~ numeral_bit[2];
assign not_numeral_bit_1 = ~ numeral_bit[1];
assign not_numeral_bit_0 = ~ numeral_bit[0];

assign not_3_and_not_2 = not_numeral_bit_3 & not_numeral_bit_2;
assign not_3_and_2 = not_numeral_bit_3 & numeral_bit[2];
assign 3_and_not_2 = numeral_bit[3] & not_numeral_bit_2;
assign not_1_and_not_0 = not_numeral_bit_1 & not_numeral_bit_0;
assign not_1_and_0 = not_numeral_bit_1 & numeral_bit[0];
assign 1_and_not_0 = numeral_bit[1] & not_numeral_bit_0;
assign 1_and_0 = numeral_bit[1] & numeral_bit[0];

assign minterm_00 = not_3_and_not_2 & not_1_and_not_0;
assign minterm_01 = not_3_and_not_2 & not_1_and_0;
assign minterm_02 = not_3_and_not_2 & 1_and_not_0;
assign minterm_03 = not_3_and_not_2 & 1_and_0;
assign minterm_04 = not_3_and_2 & not_1_and_not_0;
assign minterm_05 = not_3_and_2 & not_1_and_0;
assign minterm_06 = not_3_and_2 & 1_and_not_0;
assign minterm_07 = not_3_and_2 & 1_and_0;
assign minterm_08 = 3_and_not_2 & not_1_and_not_0;
assign minterm_09 = 3_and_not_2 & not_1_and_0;

assign 00_or_01 = minterm_00 | minterm_01;
assign 00_or_02 = minterm_00 | minterm_02;
assign 00_or_04 = minterm_00 | minterm_04;
assign 02_or_03 = minterm_02 | minterm_03;
assign 03_or_04 = minterm_03 | minterm_04;
assign 03_or_05 = minterm_03 | minterm_05;
assign 04_or_05 = minterm_04 | minterm_05;
assign 04_or_07 = minterm_04 | minterm_07;
assign 05_or_06 = minterm_05 | minterm_06;
assign 06_or_07 = minterm_06 | minterm_07;
assign 06_or_08 = minterm_06 | minterm_08;
assign 07_or_08 = minterm_07 | minterm_08;
assign 08_or_09 = minterm_08 | minterm_09;

assign 00_02_or_03_05 = 00_or_02 | 03_or_05;
assign 06_07_or_08_09 = 06_or_07 | 08_or_09;
assign a = 00_02_or_03_05 | 06_07_or_08_09;

assign 00_01_or_02_03 = 00_or_01 | 02_or_03;
assign 04_07_or_08_09 = 04_or_07 | 08_or_09;
assign b = 00_01_or_02_03 | 04_07_or_08_09;

assign 00_01_or_03_04 = 00_or_01 | 03_or_04;
assign 05_06_or_07_08 = 05_or_06 | 07_or_08;
assign minterm_temp = 00_01_or_03_04 | 05_06_or_07_08;
assign c = minterm_temp | minterm_09;

assign d = 00_02_or_03_05 | 06_or_08;

assign e = 00_or_02 | 06_or_08;

assign 00_04_or_05_06 = 00_or_04 | 05_or_06;
assign f = 00_04_or_05_06 | 08_or_09;

assign 02_03_or_04_05 = 02_or_03 | 04_or_05;
assign 06_08_or_09 = 06_or_08 | minterm_09;
assign g = 02_03_or_04_05 | 06_08_or_09;
