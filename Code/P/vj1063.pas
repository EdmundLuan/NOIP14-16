program vj1063;
var i,j,n,max:longint;
    f,g:array[0..200,0..200]of longint;
	a:array[0..200,0..200]of char;
	str:string;
function min(a,b:longint):longint;
begin
    if a>=b then
    exit(b)
    else
    exit(a);
end;
begin
    //assign(input,'D:\running zone\input.txt');
	//reset(input);
    readln(n);
	for i:=1 to n do
	begin
	    readln(str);
		for j:=1 to length(str) do
		a[i,j]:=str[j];
	end;
        {for i:=1 to 20 do
        begin
        for j:=1 to 20 do
        write(a[i,j]);
        writeln;
        end;}
        max:=0;
	fillchar(f,sizeof(f),0);
	fillchar(g,sizeof(g),0);
	for i:=1 to n do
	for j:=1 to 2*n-1 do
	begin
	    if (a[i,j]='-')and(i mod 2 = j mod 2) then
		begin
		    if a[i-1,j]<>'-' then
			f[i,j]:=1
			else
			f[i,j]:=min(f[i-1,j-1],f[i-1,j+1])+1;
		end
		else
		begin
		    if a[i+1,j]<>'-' then
			g[i,j]:=1
			else
			g[i,j]:=min(g[i+1,j-1],g[i+1,j+1])+1;
		end;
		if max<f[i,j] then
		max:=f[i,j];
                if max<g[i,j] then
                max:=g[i,j];
	end;
	writeln(max*max);
	//close(input);
end.
