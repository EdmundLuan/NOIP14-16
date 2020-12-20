program vj1418;
var i,j,k,temp,n,m:longint;
	f:array[0..1200,0..1200]of longint;
	p,e,c:array[0..2000]of longint;

begin
	readln(n,m);
	for i:=2 to n do
	begin
		read(p[i]);
	end;
	readln;
	for i:=1 to n do
		read(c[i]);
	readln;
	for i:=1 to n do
		read(e[i]);
	readln;

	for i:= n downto 2 do
	begin
		for j:=c[i] to m do
		begin
			if e[i]>f[i,j] then
				f[i,j]:=e[i];
		end;
		for k:=m downto 0 do
		begin
			for j:=0 to k do
			begin
				if f[p[i],k]<f[p[i],k-j]+f[i,j] then
					f[p[i],k]:=f[p[i],k-j]+f[i,j];
			end;
		end;
	end;
	writeln(f[1,m])
end.
