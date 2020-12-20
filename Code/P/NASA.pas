program NASA;
var v,m,i,j,n,h:longint;
    vi,mi,k:array[0..501]of longint;
    f:array[0..501,0..501]of longint;
begin
    readln(v,m);
	readln(n);
	for i:=1 to n do
	readln(vi[i],mi[i],k[i]);
	for i:=1 to n do
	begin
	    for j:=v downto 0 do
		for h:=m downto 0 do
		begin
		    if (j>=vi[i])and(h>=mi[i])and(f[j-vi[i],h-mi[i]]+k[i]>f[j,h]) then
			f[j,h]:=f[j-vi[i],h-mi[i]]+k[i];
		end;
	end;
	writeln(f[v,m]);
end.
