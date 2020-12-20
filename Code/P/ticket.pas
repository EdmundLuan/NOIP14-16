program ticket;
var L1,l2,l3,c1,c2,c3,i,j,n,a,b,len,tic:longint;
    arr,f:array[0..10001]of longint;
begin
    readln(L1,l2,l3,c1,c2,c3);
	readln(n);
	readln(a,b);
	for i:=2 to n do
	begin
	    readln(arr[i]);
	end;
	f[a]:=0;
        for i:=a+1 to b do
        f[i]:=maxlongint;
	for i:=a+1 to b do
	begin
	    for j:=a to i-1 do
		begin
		    tic:=0;
		    len:=arr[i]-arr[j];
		    if (len>l3) then
			continue;
			if len<=l1 then
			tic:=c1
			else
			begin
			   if len<=l2 then
			   tic:=c2
			   else
			   tic:=c3
			end;
			if (f[j]+tic<f[i]) then
			f[i]:=f[j]+tic;
		end;
	end;
        writeln(f[b]);
end.
