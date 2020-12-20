program fruit;
var a,b:array[0..101]of char;
    i,j,la,lb:longint;
    lcsa:array[0..101,0..101]of longint;
procedure readin;
var i,j:longint;
    x:char;
	flag:boolean;
begin
    i:=0;
	flag:=false;
	{for i:=0 to 101 do
	begin
	    for j:=0 to 101 do
	    begin
	        lcsa[i,j]:=0;
	    end;
	end;}
    while not(eoln) do
	begin
	    inc(i);
	    read(x);
		if x=' ' then
		begin
		    flag:=true;
                    la:=i-1;
                    i:=0;
			continue;
		end;
		if flag then
		begin
		    b[i]:=x;
			lcsa[0,i]:=0;
		end
		else
		begin
		    a[i]:=x;
			lcsa[i,0]:=0;
		end;
	end;
	lb:=i;
        readln;
	end;
begin
    while not(eof) do
	begin
        readin;
		for i:=1 to la do
	for j:=1 to lb do
	begin
	    if a[i]=b[j] then
		lcsa[i,j]:=lcsa[i-1,j-1]+1
		else
		begin
		    if lcsa[i-1,j]>lcsa[i,j-1] then
			lcsa[i,j]:=lcsa[i-1,j]
			else
			lcsa[i,j]:=lcsa[i,j-1];
		end;
	end;
	writeln(la+lb-lcsa[la,lb]);
	end;
	readln;
end.
