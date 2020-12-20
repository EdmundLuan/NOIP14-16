program nlxl;
var i,j,k,p,n,m:longint;
    f:array[0..500,0..500]of longint;
	head,tail:array[0..500]of longint;
begin
    readln(n);
	for i:=1 to n do
	read(head[i]);
	readln;
        for i:=1 to n-1 do
        tail[i]:=head[i+1];
        tail[n]:=head[1];
	for i:=n+1 to 2*n-1 do
	begin
	    head[i]:=head[i-n];
	    tail[i]:=tail[i-n];
	end;
        m:=2*n-1;
	fillchar(f,sizeof(f),0);
	for p:=1 to n-1 do
	for i:=1 to m-1 do
	begin
	    j:=i+p;
		if j>m then
		break;
		for k:=i to j-1 do
		begin
		    if f[i,k]+f[k+1,j]+head[i]*tail[k]*tail[j]>f[i,j] then
			f[i,j]:=f[i,k]+f[k+1,j]+head[i]*tail[k]*tail[j];
		end;
	end;
	j:=-maxlongint;
	for i:=1 to n do
	begin
	    if j<f[i,i+n-1] then
		j:=f[i,i+n-1];
	end;
	writeln(j);
	readln;
end.
