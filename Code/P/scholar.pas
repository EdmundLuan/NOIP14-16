program test;
type data=record
     stuname:string[20];
     mark1:integer;
     mark2:integer;
     officer:char;
     westerner:char;
     pages:integer;
     money:longint;
     shit:char;
     end;
var k:char;s:array [1..101] of data;
    total,max,n,i,maxstu:longint;
begin
	assign(input,'scholar.in');
	reset(input);
	assign(output,'scholar.out');
	rewrite(output);
    readln(n);
    for i:=1 to n do
    begin
     with s[i] do
      begin
         repeat
         begin
         read(k);
         stuname:=stuname+k;
         end;
         until k=' ';
         read(mark1);
         read(mark2);
         read(shit);
         read(officer);
         read(shit);
         read(westerner);
         readln(pages);
         if (mark1>80) and (pages>=1) then
         money:=money+8000;
         if (mark1>85)and(mark2>80) then
         money:=money+4000;
         if (mark1>90)then
         money:=money+2000;
         if (westerner='Y')and(mark1>85) then
         money:=money+1000;
         if (officer='Y')and(mark2>80) then
         money:=money+850;
      end;
     end;
     total:=0;
     max:=-1;
    for i:=1 to n do
    begin
       total:=total+s[i].money;
       if s[i].money>max  then
       begin
       max:=s[i].money;
       maxstu:=i;
       end;
    end;
    writeln(s[maxstu].stuname);
    writeln(max);
    writeln(total);
	close(input);
	close(output);
end.
