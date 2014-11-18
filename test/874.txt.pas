var
 key:char;
 iii,n,max,add,zd:longint;
 s:array[1..20]of string;
 ss:array[1..20]of longint;
function can(e,d:longint):boolean;
var
 x,ii,jj,k,js,a,b:longint;
 hs:boolean;
 s1,s2:string;
begin
 s1:=s[e];
 s2:=s[d];
 can:=false;
 if ss[d]<2 then
 begin
  if length(s1)>length(s2) then
   begin
    a:=length(s1);
    b:=length(s1)-length(s2)+2;
   end
    else
     begin
      a:=length(s1);
      b:=2;
     end;
  for ii:=a downto b do
   begin
    hs:=true;
    js:=1;
    for jj:=ii to a do
     if (s1[jj]<>s2[js]) then
      begin
       hs:=false;
       break;
      end
      else
       inc(js);
    if hs=true then
     begin
      add:=length(s2)-length(s1)+ii-1;
      can:=true;
      break;
     end;
   end;
  end;
end;
procedure dg(y:longint);
var
 i,j,add1:longint;
begin
 for i:=1 to n do
  if can(y,i) then
   begin
    zd:=zd+add;
    add1:=add;
    inc(ss[i]);
    if zd>max then
     max:=zd;
     dg(i);
     zd:=zd-add1;
     dec(ss[i]);
    end;
end;
begin
 readln(n);
 for iii:=1 to n do
  readln(s[iii]);
 readln(key);
 max:=0;
 fillchar(ss,sizeof(ss),0);
 for iii:=1 to n do
  if s[iii][1]=key then
   begin
    inc(ss[iii]);
    zd:=length(s[iii]);
    if zd>max then
     max:=zd;
    dg(iii);
    dec(ss[iii]);
   end;
 writeln(max);
end.
