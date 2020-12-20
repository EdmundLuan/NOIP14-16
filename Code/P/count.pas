program count;
var i,l,r,a,j:longint;
    st:string;
begin
    readln(L,R);
	for i:=L to R do
	begin
	    str(i,st);
		for j:=1 to length(st) do
		if(st[j]='2')  then
		inc(a);
	end;
	writeln(a);
end.
