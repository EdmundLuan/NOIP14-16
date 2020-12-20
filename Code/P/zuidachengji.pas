program zuidachengji;
var i,j,n,m,k:longint;
    s:string;
    f:array[0..1000,0..1000]of longint;
function num(i,j:longint):longint;
begin
    val(copy(s,i,j-i+1),num);
end;
function min(a,b:longint):longint;
begin
    if a>=b then
	min:=b
	else
	min:=a;
end;
function max(a,b:longint):longint;
begin
    if a>=b then
	max:=a
	else
	max:=b;
end;
begin
    readln(n,m);
	readln(s);
    fillchar(f,sizeof(f),0);
	for i:=1 to n do
	f[i,0]:=num(1,i);
	for i:=2 to n do
	for j:=1 to min(i-1,m) do
	for k:=j to i-1 do
	f[i,j]:=max(f[k,j-1]*num(k+1,i),f[i,j]);
	writeln(f[n,m]);
	readln;
end.
