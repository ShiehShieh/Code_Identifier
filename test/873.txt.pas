program p1059;
var f:array[0..10001]of boolean;
    a:array[0..10001]of integer;
    i,max,n:integer;
    cc:boolean;

procedure co(n:integer);
var i,j,h,x:longint;
begin
  for i:=1 to n do begin
   read(x);h:=0;
   fillchar(f,sizeof(f),false);
   f[0]:=true;
   while x<>-1 do begin
    h:=h+x;
    for j:=h downto x do
     if f[j-x] then f[j]:=true;
    read(x);
    end;
   if max<h then max:=h;
   for j:=1 to max do if f[j] then inc(a[j]);
   readln;
  end;
end;


begin
  readln(n);
  fillchar(a,sizeof(a),0);
  co(n);
  cc:=false;
  for i:=max downto 0 do
   if a[i]=n then begin write(i);cc:=true;break;end;
  if not cc then write('0');
end.
