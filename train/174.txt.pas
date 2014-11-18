program sdfsd;
type o=set of 1..50;
var i,j:integer;
      n,b,c,d,w,e,max:longint;
    a:array[1..50,1..2]  of integer;
    x:o;


function  rrr(s,t:integer) :integer;
begin
if s>t then rrr:=a[s,1] -a[t,1]  else  rrr:=a[t,1] -a[s,1];
end;


procedure  try(p:integer;b:longint; w2:integer;s:o);
 var t,y,i:integer;
begin
if w2-a[p,2]=0 then  begin  if    b<max   then max:=b; end  else
for j:=p+1 to n do
 if not( j in s ) and (b<max) then
 begin
  t:=w2-a[p,2]; y:=rrr(j,p)*t;
  {if s+[p]+[j]=x then  begin  if    b<max   then max:=b; end  else}
  try(j,b+y,t,s+[p]);
  
  break;
 end;

 for j:=p-1 downto 1 do
 if not( j in s ) and (b<max) then
 begin
  t:=w2-a[p,2]; y:=rrr(j,p)*t;
  {if s+[p]+[j]=x then  begin  if    b<max   then max:=b; end else}
  try(j,b+y,t,s+[p]);
  
  break;
 end;
end;





begin
readln(n,c);
for i:=1 to n do
  begin
  readln(a[i,1],a[i,2]);
  w:=w+a[i,2];
  end;


 max:=maxlongint;
for i:=1 to n do x:=x+[i];

try(c,0,w,[c]);
             
writeln(max);

end.
