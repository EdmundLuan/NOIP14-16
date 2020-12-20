program job;
var a:array[0..21,0..21]of longint;
    pan:array[0..21]of boolean;
	i,n,j,ans,fee:longint;
procedure dfs(k:longint);
var i:longint;
begin
    if k>n then
	begin
	    if fee<ans then
		ans:=fee;
		exit;
	end;
    for i:=1 to n do
	begin
	    if pan[i]=false then
		begin
		    fee:=fee+a[k,i];
			pan[i]:=true;
		    dfs(k+1);
			fee:=fee-a[k,i];
			pan[i]:=false;
		end;
	end;
end;
begin
    assign(input,'job.in');
    reset(input);
    assign(output,'job.out');
    rewrite(output);
    readln(n);
	for i:=1 to n do
	begin
	    for j:=1 to n do
		read(a[i,j]);
		readln;
	end;
	ans:=maxlongint;
	fee:=0;
	dfs(1);
	writeln(ans);
    close(input);
    close(output);
end.
