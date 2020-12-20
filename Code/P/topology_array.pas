program topology;
var n,m,i,j,k,x,y:longint;
    edge:array[0..1001,0..1001]of boolean;
	t,a:array[0..1001]of longint;
begin
    readln(n,m);
	fillchar(edge,sizeof(edge),0);
	fillchar(t,sizeof(t),0);
	for i:=1 to m do
	begin
	    readln(y,x);
	    if not edge[x,y] then
		begin
	        edge[x,y]:=true;
			inc(t[y]);
		end;
	end;
	for i:=n downto 1 do
	begin
	    for j:=n downto 1 do
	    if t[j]=0 then
		break;
                t[j]:=-1;
		a[j]:=i;
		for k:=1 to n do
		begin
		    if not edge[j,k] then
			continue;
			edge[j,k]:=false;
			dec(t[k]);
		end;
	end;
	for i:=1 to n do
	write(a[i],' ');
	readln;
	//readln;
end.
