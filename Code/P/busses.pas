program highwayride;
const maxn=101;
var i,j,m:longint;
    v,f:array[0..1000]of longint;
begin
	assign(input,'busses.in');
	reset(input);
	assign(output,'busses.out');
	rewrite(output);
   	for i:=1 to 10 do
	read(v[i]);
	readln(m);
	for i:=1 to maxn do
	f[i]:=maxlongint;
	f[0]:=0;
	for i:=1 to 10 do
	begin
	    for j:=i to m do
		if (f[j-i]+v[i]<f[j]) then
		f[j]:=f[j-i]+v[i];
	end;
	writeln(f[m]);
	close(input);
	close(output);
end.
