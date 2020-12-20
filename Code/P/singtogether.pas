program test;
var i,j,k,max,n:longint;
    is,ds,t:array[0..101]of longint;
begin
    readln(n);
	for i:=1 to n do
	begin
	    read(t[i]);
	    is[i]:=1;
		ds[i]:=1;
	end;
	for i:=n-1 downto 1 do
	begin
	    max:=0;
	    for j:=i+1 to n do
		begin
		    if (t[j]>t[i])and(is[j]>max) then
			max:=is[j];
			is[i]:=max+1;
		end;
	end;
	for i:=n-1 downto 1 do
	begin
	    max:=0;
	    for j:=i+1 to n do
		begin
		    if (t[j]<t[i])and(ds[j]>max) then
			max:=ds[j];
			ds[i]:=max+1;
		end;
	end;
	for i:=1 to n do
	begin
	    k:=ds[i]+is[i]-1;
	    if max<k then
	    max:=k;
	end;
	writeln(max);
end.