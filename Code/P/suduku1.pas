program suduku;
var i,j,s,t,max:longint;
    px,py,pz:array [1..12,1..12] of boolean;
	map:array [0..12,0..12] of longint;
	x:char;
	flag:boolean;
function gongge(a,b:longint):longint;
var i,j:real;
    t1,t2:longint;
begin
	 i:=max;
	 j:=sqrt(max);
	 t1:=trunc(j);
	 while not((a>(i-j))and(a<=i)) do
	 begin
	     i:=i-j;
		 dec(t1);
	 end;
	 i:=max;
	 j:=sqrt(max);
	 t2:=trunc(j);
	 while not((b>(i-j))and(b<=i)) do
	 begin
	     i:=i-j;
		 dec(t2);
	 end;
	 gongge:=(t1-1)*(trunc(j))+t2;
end;
function judge(a,b,c,d:longint):boolean;
begin
    if (px[a,c]=false)and(py[b,c]=false)and(pz[d,c]=false) then
	exit(true)
	else
	exit(false);
end;
procedure print(z:longint);
var i,j:longint;
begin
     writeln('Answer',' ',z,' ',':');
	 for i:=1 to max do
	 begin
	     for j:=1 to max do
		 write(map[i,j]);
		 writeln;
	 end;
end;
procedure recognize(a,b:longint);
begin
     case map[a,b] of
	 0:begin
	       inc(s);
	   end;
         else
         begin
	          px[a,map[a,b]]:=true;
			  py[b,map[a,b]]:=true;
			  pz[gongge(a,b),map[a,b]]:=true;
         end;
	 end;
end;
procedure dfs(i,j,k:longint);
var e,f,g,sheng,gg:longint;
begin
     gg:=gongge(i,j);
     sheng:=k;
	 for e:=1 to max do
	 begin
	     if judge(i,j,e,gg) then
		 begin
		     map[i,j]:=e;
			 dec(sheng);
			 if sheng=0 then
	         begin
	              inc(t);
	              print(t);
		          exit;
	         end;
			 px[i,e]:=true;
			 py[j,e]:=true;
			 pz[gg,e]:=true;
			 for f:=i to max do
			 for g:=j to max do
			 begin
			     if map[f,g]=0 then
				 dfs(f,g,k-1);
			 end;
			 px[i,e]:=false;
			 py[j,e]:=false;
			 pz[gg,e]:=false;
			 map[i,j]:=0;
			 inc(sheng);
		 end;
	 end;
end;
begin
     repeat
	 writeln('please enter a "wan quan ping fang shu"');
     readln(max);
	 if frac(sqrt(max))=0 then
	 flag:=true;
	 until flag;
	 writeln('Enter the task');
	 for i:=1 to max do
	 begin
	    for j:=1 to max do
	    begin
		    read(x);
		    map[i,j]:=ord(x)-48;
			recognize(i,j);
		end;
		readln;
	 end;
	 for i:=1 to max do
	 for j:=1 to max do
	     begin
		     if map[i,j]=0 then
			 begin
			    dfs(i,j,s);
                readln;
			    halt;
			 end;
		 end;
	 writeln('R u fking kiding me?');
end.
