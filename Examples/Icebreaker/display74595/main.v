`timescale 1ns / 1ps
//define our module and it's inputs/outputs
module top(
	input CLK,
	output P2_1,
	output P2_2,
	output P2_3,
	output P2_4,
	output P2_7,
	output P2_8,
	output P2_9,
	output P2_10,
	output LEDR_N,
	output LEDG_N
    );

//define wires and registers here
	reg [22:0] slowdowncounter;

	reg OE;
	reg LAT;
	//reg DCLK = 0;
	reg SER;

	reg [3:0] line;
	reg [1:0] linecounter;
	reg [7:0] linebuffer;
	reg [3:0] columncounter;
	reg commitrow = 0;

	reg [7:0] framebuffer [0:3];

	reg [7:0] lfsr = 1;
	reg update = 0;

//parallel assignments can go here
	assign P2_1 = line[0];
	assign P2_2 = line[1];
	assign P2_3 = line[2];
	assign P2_4 = line[3];

	assign P2_7 = OE;
	assign P2_8 = LAT;
	//assign P2_9 = CLK;
	assign P2_9 = slowdowncounter[0];
	assign P2_10 = SER;

	assign LEDG_N = slowdowncounter[20];
	assign LEDR_N = !slowdowncounter[20];

//always @ blocks can go here
	always @(posedge CLK) begin
		slowdowncounter <= slowdowncounter + 1;
	end

	always @(posedge slowdowncounter[0]) begin

		begin
			case (linecounter)
				2'b00:begin
					line = 4'b0001;
				end
				2'b01:begin
					line = 4'b0010;
				end
				2'b10:begin
					line = 4'b0100;
				end
				2'b11:begin
					line = 4'b1000;
				end
			endcase
		end

		if (columncounter == 0 && commitrow == 0) begin
			LAT <= 1;
			OE <= 1;
			linecounter <= linecounter +1;
			commitrow <= 1;
			linebuffer <= framebuffer[linecounter+2];
		end else begin
			LAT <= 0;
			OE <= 0;
			commitrow <= 0;
			SER <= linebuffer[columncounter];
			columncounter <= columncounter+1;
		end

		if (slowdowncounter[20] == 1 && update == 0) begin
			if(columncounter == 0 && linecounter == 0) begin
				update <= 1;
				//lfsr <= {lfsr[6:0],~(lfsr[7]^lfsr[2])};

				framebuffer[3] <= framebuffer[2];
				framebuffer[2] <= framebuffer[1];
				framebuffer[1] <= framebuffer[0];
				framebuffer[0] <= framebuffer[0] + 1;
				//framebuffer[0] <= lfsr;


				
				//framebuffer[0] <= framebuffer[0] + 1;
				//if (framebuffer[0]==255) begin
				//	framebuffer[1] <= framebuffer[1] + 1;
				//	if (framebuffer[1]==255) begin
				//		framebuffer[2] <= framebuffer[2] + 1;
				//		if (framebuffer[2]==255) begin
				//			framebuffer[3] <= framebuffer[3] + 1;
				//		end
				//	end
				//end
			end
		end else if (slowdowncounter[20] == 0) begin
			update <= 0;
		end
	end
endmodule



