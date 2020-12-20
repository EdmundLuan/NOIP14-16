program water;
var i,n,x,max,s:longint;
    a:array[0..200001]of longint;
procedure quicksort(l,r:longint);
var mid,tl,tr,tmp:longint;
begin
    mid:=a[(l+r)div 2];
	tl:=l;tr:=r;
        repeat
	while a[tl]<mid do
	inc(tl);
	while a[tr]>mid do
	dec(tr);
	if(tl<=tr) then
	begin
	    tmp:=a[tl];
		a[tl]:=a[tr];
		a[tr]:=tmp;
		inc(tl);dec(tr);
	end;
        until tl>tr;
	if tl<r then
	quicksort(tl,r);
	if(tr>l) then
	quicksort(l,tr);
end;

begin
    readln(n);
	max:=-maxlongint;
	for i:=1 to n do
	begin
	    readln(x);
	    a[i]:=x;
		if x>max then
		max:=x;
	end;
	if n=1 then
	begin
	    writeln(a[1],' ',1);
		halt;
	end;
	quicksort(1,n);
	s:=1;
	for i:=2 to n do
	begin
	    if a[i]<>a[i-1] then
		begin
		    writeln(a[i-1],' ',s);
			s:=1;
		end
		else
		inc(s);
		if i=n then
		writeln(a[n],' ',s);
	end;
end.
