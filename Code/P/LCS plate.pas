program LCS;
var a,b:array[0..2001]of char;
    i,j,la,lb:longint;
	lcsa:array[0..2001,0..2001]of longint;
procedure readin;
var i:longint;
    x:char;
	flag:boolean;
begin
    i:=0;
	flag:=false;
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
end;
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
	writeln(lcsa[la,lb]);
	readln;
end.
