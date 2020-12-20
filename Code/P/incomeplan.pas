program incomeplan;
var n,m,i,max,mid:longint;l,r:int64;
    a:array[0..100001]of longint;
function takemoney(k:longint):longint;
var t,count,i:longint;
begin
     t:=0;
	 count:=0;
     for i:=1 to n do
	 begin
	     if t+a[i]<=k then
		 begin
		     t:=t+a[i];
		 end
		 else
		 begin
		     inc(count);
			 t:=a[i];
		 end;
	 end;
	 takemoney:=count+1;
end;
begin
     readln(n,m);
     max:=0;
     for i:=1 to n do
     begin
          readln(a[i]);
          if a[i]>max then
          max:=a[i];
     end;
     l:=max;
     r:=maxlongint+100000;
     while l<>r do
     begin
         mid:=(l+r)div 2;
         if takemoney(mid)<=m then
		 l:=mid+1
		 else
		 r:=mid;
         //writeln(l,' ',r);
	 end;
	 writeln(l);
	 readln;
end.
