program wormi;
var i,j,n,f,dx,dy:longint;
	worm:array [0..20,0..2]of longint;
	tx:array [0..20]of longint;
	ty:array [0..20]of longint;
    chr:char;

function check:longint;
var p:longint;
begin
	if (worm[0,0]<1)or(worm[0,0]>50)or(worm[0,1]<1)or(worm[0,1]>50) then
	exit(1);
	for p:=1 to 19 do
	begin
		if (worm[p,0]=worm[0,0])and(worm[p,1]=worm[0,1]) then
		exit(2);
	end;
	exit(0);
end;

begin
	readln(n);
	while(n<>0) do
	begin
		worm[0,0]:=30;
		worm[0,1]:=25;
		for i:=1 to 19 do
		begin
			worm[i,0]:=worm[i-1,0]-1;
			worm[i,1]:=25;
		end;
		
		for i:=1 to n do
		begin
		    read(chr);
			case chr of
				'E':begin
						dx:=1;
						dy:=0;
					end;
				'W':begin
						dx:=-1;
						dy:=0;
					end;
				'N':begin
						dx:=0;
						dy:=-1;
					end;
				'S':begin
						dx:=0;
						dy:=1;
					end;
			end;
			
			for j:=0 to 19 do
			begin
				tx[j]:=worm[j,0];
				ty[j]:=worm[j,1];
			end;
			worm[0,0]:=worm[0,0]+dx;
			worm[0,1]:=worm[0,1]+dy;
			for j:=1 to 19 do
			begin
				worm[j,0]:=tx[j-1];
				worm[j,1]:=ty[j-1];
			end;
			f:=check;
			if f=1 then
			begin
				writeln('The worm ran off the board on move ',i,'.');
				break;
			end;
			if f=2 then
			begin
				writeln('The worm ran into itself on move ',i,'.');
				break;
			end;
		end;
		if f=0 then
		writeln('The worm successfully made all ',i,' moves.');
		readln;
                readln(n);
	end;
end.
