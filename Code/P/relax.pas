program relax;
type node=record
     u:longint;
	 v:longint;
	 dist:longint;
	 end;
var father:array [0..100000] of longint;
    info:array [0..100000]of node;
	i,y,x,n,m,min:longint;
function max(a,b:longint):longint;
begin
    if a>=b then
    exit(a)
    else
    exit(b);
end;
procedure origin(n:longint);
var i:longint;
begin
    for i:=1 to n do
    begin
    father[i]:=i;
    end;
end;
function getfather(a:longint):longint;
begin
    if father[a]=a then
	exit(a);
	father[a]:=getfather(father[a]);
	exit(father[a]);
end;
procedure unionn(a,b:longint);
var fu,fv:longint;
begin
    fu:=getfather(a);
	fv:=getfather(b);
	if fu<>fv then
	father[fu]:=fv;
end;
procedure quicksort(l,r:longint);
var tl,tr,mid:longint;
    tmp:node;
begin
    tl:=l;tr:=r;
    mid:=info[(l+r)div 2].dist;
    repeat
        while info[tl].dist<mid do
        inc(tl);
        while info[tr].dist>mid do
        dec(tr);
        if tl<=tr then
        begin
            tmp:=info[tl];
            info[tl]:=info[tr];
            info[tr]:=tmp;
            inc(tl);dec(tr);
        end;
    until tl>tr;
    if tl<r then
    quicksort(tl,r);
    if tr>l then
    quicksort(l,tr);
end;
begin
    //assign(input,'relax.in');
    //reset(input);
   // assign(output,'relax.out');
    //rewrite(output);
    readln(n,m);
	origin(n);
	for i:=1 to m do
	    readln(info[i].u,info[i].v,info[i].dist);
       quicksort(1,m);
       min:=-maxlongint;
       for i:=1 to m do
       begin
          unionn(info[i].u,info[i].v);
          min:=max(info[i].dist,min);
          if father[1]=father[n] then
          begin
              writeln(min);
              halt;
          end;
       end;
	writeln('-1');
        //close(input);
       // close(output);
end.
