program vj1057;
var a,f:array[-1..1001,-1..1001]of longint;
    i,j,m,n,max:longint;
function min(a,b:longint):longint;
begin
    if a>=b then
	exit(b)
	else
	exit(a);
end;
begin
    //assign(input,'D:\running zone\input.txt');
    //reset(input);
    readln(n,m);
	for i:=1 to n do
	begin
	    for j:=1 to m do
		read(a[i,j]);
		readln;
	end;
	fillchar(f,sizeof(f),0);
	for i:=1 to n do
    f[i,1]:=a[i,1];
	for i:=1 to m do
	f[1,m]:=a[1,m];
	max:=0;
	for i:=1 to n do
	for j:=1 to m do
	begin
	    if a[i,j]=0 then
		continue;
		f[i,j]:=min(f[i-1,j],min(f[i-1,j-1],f[i,j-1]))+1;
		if max<f[i,j] then
		max:=f[i,j];
	end;
	writeln(max);
    //close(input);
end.
