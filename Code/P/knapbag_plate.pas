program knapbag_plate;
var m,n,i,j:longint;
    w,v,f:array[0..1000]of longint;
begin
    readln(m,n);
	for i:=1 to n do
	readln(w[i],v[i]);
	f[0]:=0;
	for i:=1 to n do
	begin
		for j:=w[i] to m do //another way,look down there.
		begin
		    if (f[j-w[i]]+v[i])>f[j] then
			f[j]:=f[j-w[i]]+v[i];
		end;
		{for j:=0 to m do
		  begin
		     if (j>=w[i])and((f[j-w[i]]+v[i])>f[j]) then
			 f[j]:=f[j-w[i]]+v[i];
		  end;
		}
	end;
	writeln(f[m]);
	readln;
end.
	
