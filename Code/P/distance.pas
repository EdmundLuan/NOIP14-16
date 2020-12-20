program distance;
var sa,sb:ansistring;
    k,i,j,la,lb,a,b,c:longint;
	lcsa:array[0..2001,0..2001]of longint;
function min(a,b,c:longint):longint;
var m:longint;
begin
    m:=maxlongint;
	if a<m then
	m:=a;
	if b<m then
	m:=b;
	if c<m then
	m:=c;
	min:=m;
end;
begin
    readln(sa);
	readln(sb);
	readln(k);
	la:=length(sa);
	lb:=length(sb);
	lcsa[0,0]:=0;
	for i:=1 to la do
	lcsa[i,0]:=lcsa[i-1,0]+k;
	for j:=1 to lb do
	lcsa[0,j]:=lcsa[0,j-1]+k;
	for i:=1 to la do
	for j:=1 to lb do
	begin
	    a:=lcsa[i-1,j-1]+abs(ord(sa[i])-ord(sb[j]));
		b:=lcsa[i-1,j]+k;
		c:=lcsa[i,j-1]+k;
		lcsa[i,j]:=min(a,b,c);
	end;
	writeln(lcsa[la,lb]);
    readln;
end.
