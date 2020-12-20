program xiaofeixia;
var n,t,i,j:longint;
    ti,fi,f:array[0..1001]of longint;
begin
    readln(n);
	readln(t);
	for i:=1 to n do
	begin
	    readln(fi[i],ti[i]);
	end;
	for i:=1 to n do
	for j:=t downto 0 do
	begin
	    if (j>=ti[i])and(f[j-ti[i]]+fi[i]>f[j]) then
		f[j]:=f[j-ti[i]]+fi[i];
	end;
	writeln(f[t]);
end.
