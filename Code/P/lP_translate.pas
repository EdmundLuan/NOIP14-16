program translate(input,output);
var total_number_of_words:longint;
    arr:array[0..10000]of char;
procedure readin;
var larr,ls,i:longint;
    str:string;
begin
     {writeln('Please input the words u wanna translate.');
	 writeln('[U should type an "@" when u finish]');}
	 total_number_of_words:=0;
	 repeat
	 begin
	     readln(str);
		 ls:=length(str);
		 larr:=total_number_of_words;
		 for i:=larr+1 to larr+ls do
		 begin
		     arr[i]:=str[i-larr];
			 inc(total_number_of_words);
		 end;
		 arr[larr+ls+1]:='~';
		 inc(total_number_of_words);
	 end;
	 until str[ls]='@';
end;
procedure Binary(fig:longint);
var brr:array [0..255]of integer;
    a,i:longint;
begin
     if fig=126 then
     begin
	 writeln;
         exit;
     end;
     if fig=92 then
     begin
         write('\');
         exit;
     end;
	 a:=fig;
	 for i:=1 to 8 do
	 begin
	     brr[i]:=(a mod 2);
		 a:=a div 2;
	 end;
         for i:=8 downto 1 do
         write(brr[i]);
	 write('%');
end;
procedure trans_output;
var i,k:longint;
begin
     for i:=1 to total_number_of_words do
	 begin
	     case ord(arr[i]) of
		 65..126:k:=ord(arr[i]);
		 32:k:=ord('\');
		 33..63:k:=ord(arr[i]);
                 else
                 continue;
	     end;
             Binary(k);
	 end;
         write('@');
end;
begin
     assign(input,'D:\running zone\words.txt');
     reset(input);
     assign(output,'D:\running zone\printedition.txt');
     rewrite(output);
     readin;
     trans_output;
     close(input);
     close(output);
end.
