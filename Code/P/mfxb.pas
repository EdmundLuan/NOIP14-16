program freepie;
var w,h,i,j,k:longint;
    f:array[0..1001,0..101]of longint;
	info:array[0..1001,0..101]of longint;
procedure init;
var time,x,v,s:longint;
begin
    readln(w,h);
	x:=0;
	s:=0;
	v:=0;
	time:=0;
	while not(eof) do
	begin
		readln(time,x,v,s);
		if (((h-1)mod v)=0)then
		begin
		    info[((h-1) div v)+time,x]:=s+info[((h-1) div v)+time,x];
		end;
	end;
	fillchar(f,sizeof(f),0);
end;
procedure dp;
begin
    for k:=1000 downto 0 do
	for i:=1 to 100 do
	begin
	    if(i-1>=1)and(f[k+1,i-1]+info[k,i]>f[k,i]) then
		f[k,i]:=f[k+1,i-1]+info[k,i];
		if(i+1<=w)and(f[k+1,i+1]+info[k,i]>f[k,i]) then
		f[k,i]:=f[k+1,i+1]+info[k,i];
		if(i-2>=1)and(f[k+1,i-2]+info[k,i]>f[k,i]) then
		f[k,i]:=f[k+1,i-2]+info[k,i];
		if(i+2<=w)and(f[k+1,i+2]+info[k,i]>f[k,i]) then
		f[k,i]:=f[k+1,i+2]+info[k,i];
	end;
end;
procedure output;
begin
    writeln(f[0,(w div 2)+1]);
end;
begin
    assign(input,'D:\running zone\input.txt');
	reset(input);
    init;
	dp;
	output;
	close(input);
end.
