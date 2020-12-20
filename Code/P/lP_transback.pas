program transback;
var str:ansistring;
    k:char;
	i,ls,word:longint;
function cifang(a,b:longint):longint;
var c,j:longint;
begin
    c:=1;
    for j:=1 to b do
    c:=c*a;
    cifang:=c;
end;
procedure decimal(a:longint);
var i:longint;
begin
    word:=0;
    for i:=a to a+7 do
	begin

	    word:=word+(ord(str[i])-48)*cifang(2,a+7-i);
	end;
	write(chr(word));
end;
begin
    assign(input,'D:\running zone\printedition.txt');
    reset(input);
    assign(output,'D:\running zone\t_b_words.txt');
    rewrite(output);
    while not(eof) do
	begin
	    readln(str);
		ls:=length(str);
		i:=1;
		while i<=ls do
		begin
		    k:=str[i];
		    if k='%' then
			begin
                            if i=ls then
                            writeln;
			    inc(i);
                            continue;
			end;
			if k='\' then
			begin
			    write(' ');
                            if i=ls then
                            writeln;
				inc(i);
				continue;
			end;
			if (k='0')or(k='1') then
			begin
			    decimal(i);
				i:=i+8;
                                continue;
			end;
                        if k<>'@' then
                        begin
                            write(k);
                            inc(i);
                            continue;
                        end
                        else
                        inc(i);
		end;
	end;
        close(input);
        close(output);
end.
