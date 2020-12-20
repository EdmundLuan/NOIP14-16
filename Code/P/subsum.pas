program subsum;
var n,c,i,mem:longint;
    s,ans:array[0..7001]of longint;
procedure quicksort(l,r:longint);
var mid,tl,tr,tmp:longint;
begin
     tl:=l;
	 tr:=r;
	 mid:=s[(l+r)div 2];
	 repeat
	     while s[tl]<mid do
		 inc(tl);
		 while s[tr]>mid do
		 dec(tr);
		 if tl<=tr then
		 begin
		     tmp:=s[tl];
			 s[tl]:=s[tr];
			 s[tr]:=tmp;
                         inc(tl);
                         dec(tr);
		 end;
	 until tl>tr;
	 if l<tr then
	 quicksort(l,tr);
	 if tl<r then
	 quicksort(tl,r);
end;
procedure dfs(x,y,z:longint);
var i:longint;
begin
    if z=c then
	begin
	    for i:=1 to y do
		write(ans[i],' ');
		halt;
	end;
    for i:=x downto 1 do
	begin
	    ans[y+1]:=s[i];
		dfs(x-1,y+1,z+ans[y+1]);
	end;
end;
function find(l,r:longint):longint;
var mid:longint;
begin
    while (r-l)>1 do
	begin
	    mid:=(l+r)div 2;
		if c>=s[mid] then
		l:=mid
		else
		r:=mid-1;
	end;
	if r>c then
	exit(l)
	else
	exit(r);
end;
function qiuhe(a,b:longint):longint;
var i,k:longint;
begin
    i:=a;
    k:=0;
    while i<=b do
    begin
    k:=k+s[i];
    inc(i);
    end;
    exit(k);
end;
procedure erfen(l,r:longint);
var mid:longint;
begin
    if qiuhe(l,r)<c then
	exit;
	mid:=s[(l+r)div 2];
	if mid=c then
	begin
	    writeln(c);
		halt;
	end;
	if mid>c then
	begin
	    erfen(l,(l+r)div 2);
	end
	else
	begin
	    mem:=find(l,r);
	    dfs(mem,0,0);
		writeln('No solution!');
		halt;
	end;
end;
begin
    assign(input,'subsum.in');
    reset(input);
    assign(output,'subsum.out');
    rewrite(output);
    readln(n,c);
	for i:=1 to n do
	read(s[i]);
	quicksort(1,n);
	erfen(1,n);
    close(input);
    close(output);
end.
