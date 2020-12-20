program aplusb;
const max=2550;
var aaa,bbb:ansistring;
	nn,i:longint;
function plus(n1,n2:ansistring):ansistring;
var
  a,b,d:array[1..max] of integer;
  lena,lenb,lenc,i,x:longint;
  q:ansistring;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  lena:=length(n1);
  for i:=1 to lena do
    a[lena-i+1]:=ord(n1[i])-ord('0');
  lenb:=length(n2);
  for i:=1 to lenb do
    b[lenb-i+1]:=ord(n2[i])-ord('0');
  x:=0;
  if lena>lenb then
	lenc:=lena
  else
    lenc:=lenb;
  For i:=1 to lenc do
  begin
    d[i]:=a[i]+b[i]+x;
    x:=d[i] div 10;
    d[i]:=d[i] mod 10;
  end;
  if x>0 then
    inc(lenc);
  d[i+1]:=x;
  plus:='';
  for i:=lenc downto 1 do
  begin
    str(d[i],q);
    plus:=plus+q;
  end;
  plus:=plus;
end;

function minus(n1,n2:ansistring):ansistring;
var
  a,b:array[1..max] of longint;
  n,q:ansistring;
  lena,lenb,i,j:longint;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  minus:='';
  if (length(n1)<length(n2)) or (length(n1)=length(n2)) and (n1<n2) then
  begin
    n:=n1;
    n1:=n2;
    n2:=n;
    minus:='-';
  end;
  lena:=length(n1);
  lenb:=length(n2);
  for i:=1 to lena do
    a[lena-i+1]:=ord(n1[i])-ord('0');
  for i:=1 to lenb do
    b[lenb-i+1]:=ord(n2[i])-ord('0');
  i:=1;
  while i<=lena do
  begin
    if a[i]<b[i] then
    begin
      a[i]:=a[i]+10;
      a[i+1]:=a[i+1]-1;
    end;
    a[i]:=a[i]-b[i];
    i:=i+1;
  end;
  while(a[i]=0) and (i>1) do
    dec(i);
  for j:=i downto 1 do
  begin
    str(a[j],q);
    minus:=minus+q;
  end;
end;
begin
	assign(input,'aplusb.in');
	reset(input);
	assign(output,'aplusb.out');
	rewrite(output);
	readln(aaa);
	readln(bbb);
	if (aaa[1]='-')and(bbb[1]='-') then
	begin
		nn:=length(aaa);
		for i:=2 to nn do
		begin
			aaa[i-1]:=aaa[i];
		end;
		delete(aaa,nn,1);
		nn:=length(bbb);
		for i:=2 to nn do
		begin
			bbb[i-1]:=bbb[i];
		end;
		delete(bbb,nn,1);
		writeln('-',plus(aaa,bbb));
	end
	else
	begin
		if (aaa[1]='-') then
		begin
			nn:=length(aaa);
			for i:=2 to nn do
			begin
				aaa[i-1]:=aaa[i];
			end;
			delete(aaa,nn,1);
			writeln(minus(bbb,aaa));
		end
		else
		begin
			if (bbb[1]='-') then
			begin
				nn:=length(bbb);
				for i:=2 to nn do
				begin
					bbb[i-1]:=bbb[i];
				end;
				delete(bbb,nn,1);
				writeln(minus(aaa,bbb));
			end
			else
			writeln(plus(aaa,bbb));
		end;
	end;
	close(input);
	close(output);
end.
