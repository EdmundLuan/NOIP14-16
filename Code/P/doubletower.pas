program doubletower;
var f:array[0..101,0..2001]of longint;
    h:array[0..101]of longint;
    i,j,n,c:longint;
function max(a,b:longint):longint;
begin
    if a>b then
	max:=a
	else
	max:=b;
end;
begin
    readln(n);
	for i:=1 to n do
	begin
	    read(h[i]);
		c:=c+h[i];
	end;
	for i:=0 to n do
	for j:=0 to c do
	f[i,j]:=-maxlongint;
	f[0,0]:=0;
	for i:=1 to n do
	for j:=c downto 0 do
	begin
	    if j>=h[i] then
		f[i,j]:=max(f[i-1,j],max(f[i-1,j-h[i]]+h[i],f[i-1,j+h[i]]));
		if j<h[i] then
		f[i,j]:=max(f[i-1,j],max(f[i-1,h[i]-j]+j,f[i-1,h[i]+j]));
	end;
	if f[n,0]>0 then
	writeln(f[n,0])
	else
	writeln('Impossible');
end.
