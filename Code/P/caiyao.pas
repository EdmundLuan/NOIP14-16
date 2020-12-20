program caiyao;
var t,m,i,j:longint;
    f,time,v:array[0..1001]of longint;
begin
    readln(t,m);
	for i:=1 to m do
	begin
	    read(time[i],v[i]);
		readln;
	end;
	for i:=1 to m do
	for j:=t downto 0 do
	begin
	    if (j>=time[i])and(f[j-time[i]]+v[i]>f[j]) then
		f[j]:=f[j-time[i]]+v[i];
	end;
	writeln(f[t]);
end.
