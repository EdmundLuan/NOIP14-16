program track;
var a,b,c,d:string;
	ans1,n,i,j,op:longint;
	operation,ans:array[0..27,0..3]of char;
    outt:array[0..27]of char;

{ type node=record
	h:chr;
end;
 }



procedure dfs(x:longint);
var pox,la,lb,lc,ld,i,j:longint;
begin
	if x=0 then
	begin
		if (op<ans1) then
		begin
			ans1:=op;
			for i:=1 to op do
				for j:=1 to 3 do
				ans[i][j]:=operation[i][j];
		end;
                exit;
	end;
	pox:=pos(outt[x],a);
	if pox<>0 then
	begin
		la:=length(a);
		if la>=pox+1 then
		begin
			b:=b+a[la];
			inc(op);
			operation[op][1]:=a[la];operation[op][2]:='A';operation[op][3]:='B';
			delete(a,la,1);
			dfs(n);
			lb:=length(b);
			c:=c+b[lb];
			operation[op][1]:=b[lb];operation[op][2]:='A';operation[op][3]:='C';
			delete(b,lb,1);
			dfs(x);
			lc:=length(c);
			a:=a+c[lc];delete(c,lc,1);
		end;
		inc(op);
		operation[op][1]:=outt[x];
		operation[op][2]:='A';
		operation[op][3]:='D';
		d:=d+a[la];
		delete(a,la,1);
		dfs(x-1);
		ld:=length(d);
		a:=a+d[ld];delete(d,ld,1);
	end
	else
	begin
		pox:=pos(outt[x],b);
		if(pox<>0) then
		begin
			lb:=length(b);
			if lb>=pox+1 then
			begin
				c:=c+b[lb];
				inc(op);
				operation[op][1]:=b[lb];operation[op][2]:='B';operation[op][3]:='C';
				delete(b,lb,1);
				dfs(x);
				lc:=length(c);
				b:=b+c[lc];delete(c,lc,1);
			end;
			inc(op);
			d:=d+b[lb];
			operation[op][1]:=outt[x];
			operation[op][2]:='B';
			operation[op][3]:='D';
			delete(b,lb,1);
			dfs(x-1);
			ld:=length(d);
			b:=b+d[ld];delete(d,ld,1);
		end
		else
		begin
			lc:=length(c);
			if c[lc]<>outt[x] then
			exit;
			inc(op);
			d:=d+c[lc];
			operation[op][1]:=outt[x];
			operation[op][2]:='C';
			operation[op][3]:='D';
			delete(c,lc,1);
			dfs(x-1);
			ld:=length(d);
			c:=c+d[ld];delete(d,ld,1);
		end;
	end;
end;

begin
	assign(input,'track.in');
	reset(input);
	assign(output,'track.out');
	rewrite(output);
	readln(n);
	for i:=1 to n do
		read(outt[i]);
        readln;
	
	for i:=1 to n do
		a:=a+chr(i+96);
	ans1:=maxlongint;
	dfs(n);
	if ans1=maxlongint then
	begin
		writeln('NO');
		halt;
	end;
	for i:=1 to ans1 do
		writeln(ans[i][1],' ',ans[i][2],' ',ans[i][3]);
	close(input);
	close(output);
end.
