program k_big;
var i,n,k:longint;
    a:array[0..100001]of longint;
procedure quicksort(l,r:longint);
var mid,tl,tr,tmp:longint;
begin
    mid:=a[(l+r)div 2];
	tl:=l;tr:=r;
        repeat
	while a[tl]>mid do
	inc(tl);
	while a[tr]<mid do
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
    fillchar(a,sizeof(a),0);
    readln(n,k);
	for i:=1 to n do
	read(a[i]);
	quicksort(1,n);
	writeln(a[k]);
end.
