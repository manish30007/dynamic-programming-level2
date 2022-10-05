module fulladder(a,b,ic,o,oc);
 
input a,b,ic;
 
output o,oc;
 
assign o = (~ic & ((a & ~b) | (~a & b)) ) | (ic & ~((a & ~b) | (~a & b)) );
 
assign oc = (a & b) | (b & ic) | (ic & a);
 
endmodule
module main(in1,in2,ic,out,oc);
 
input [3:0]in1;
 
input [3:0]in2;
 
input ic;
 
output [3:0]out;
 
output [3:0]oc;
 
fulladder fa1(in1[0],in2[0],ic,out[0],oc[0]);
 
fulladder fa2(in1[1],in2[1],oc[0],out[1],oc[1]);
 
fulladder fa3(in1[2],in2[2],oc[1],out[2],oc[2]);
 
fulladder fa4(in1[3],in2[3],oc[2],out[3],oc[3]);
 
endmodule
Testbench:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
module adder_tb;
 
wire [3:0]oc;
 
wire [3:0]out;
 
reg [3:0]in1;
 
reg [3:0]in2;
 
reg ic;
 
main m(.oc(oc), .in1(in1), .in2(in2), .out(out), .ic(ic) );
 
initial
 
begin
 
$monitor(" ",in1," ",in2," ",out," ",oc[3]);
 
in1=4'b1010;
 
in2=4'b1001;
 
ic=0;
 
end
 
endmodule