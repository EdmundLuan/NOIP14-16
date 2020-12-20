program jingweitianhai;
var i,j,min,n,v,c:longint;
    f,m,k:array[0..100001]of longint;
begin
    readln(v,n,c);
	for i:=1 to n do
	readln(k[i],m[i]);
	min:=maxlongint;
	for i:=1 to n do
	for j:=c downto 1 do
	begin
	    if (j>=m[i])and(f[j-m[i]]+k[i]>f[j]) then
		f[j]:=f[j-m[i]]+k[i];
		if (f[j]>=v)and(j<min) then
		min:=j;
	end;
        if min=maxlongint then
        begin
            writeln('Impossible');
            halt;
        end;
        writeln(c-min);
end.
