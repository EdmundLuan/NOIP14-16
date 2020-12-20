program robot;
var f:array [0..101,0..101,0..2]of longint;
    map:array[0..101,0..101]of longint;
    m,n,i,j:longint;
function max(a,b:longint):longint;
begin
    if a>b then
	max:=a
	else
	max:=b;
end;
procedure init;
begin
    readln(n,m);
	for i:=1 to n do
    begin
	    for j:=1 to m do
		read(map[i,j]);
		readln;
	end;
	fillchar(f,sizeof(f),0);
        //f[1,1,1]:=1;
	for i:=1 to n do
        begin
	f[i,1,1]:=1;
        //f[i,0,1]:=1;
        end;
	for i:=1 to m do
        begin
	f[1,i,1]:=1;
        //f[0,i,1]:=1;
        end;
        f[0,1,1]:=1;//This is the special step!!
end;
procedure dp;
begin
    for i:=1 to n do
	for j:=1 to m do
	begin
	    f[i,j,0]:=max(f[i-1,j,0]+map[i,j],f[i,j-1,0]+map[i,j]);
		if f[i-1,j,0]>f[i,j-1,0] then
		f[i,j,1]:=f[i-1,j,1]
                else
                begin
                if f[i,j-1,0]>f[i-1,j,0] then
		f[i,j,1]:=f[i,j-1,1]
                else
                f[i,j,1]:=f[i-1,j,1]+f[i,j-1,1];
                end;
                {if f[i-1,j,0]=f[i,j-1,0] then
                f[i,j,1]:=f[i-1,j,1]+f[i,j-1,1]
                else
                f[i,j,1]:=1;}
	end;
end;
procedure output;
begin
    writeln(f[n,m,0],' ',f[n,m,1]);
    //writeln(f[1,1,1]);
end;
begin
    assign(input,'D:\running zone\input.txt');
	reset(input);
    init;
	dp;
	output;
	close(input);
end.
