program zhuangxiang;
var vm,n,i,j:longint;
    v:array[0..31]of longint;
	f:array[0..200001]of boolean;
begin
    readln(vm);
	readln(n);
	for i:=1 to n do
	readln(v[i]);
        f[0]:=true;
	for i:=1 to n do
	for j:=vm downto v[i] do
	begin
	    f[j]:=f[j] or f[j-v[i]];
	end;
	for i:=vm downto 0 do
	begin
	    if f[i] then
	    break;
	end;
	writeln(vm-i);
end.
