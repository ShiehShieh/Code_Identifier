var
 name:array[1..11]of string;
 money:array[1..11]of longint;
 i,j,k,n,g,x,t,p,ren:longint;
 s,str:string;function
 find(mn:string):integer;
begin
 for t:=1 to n do
 if name[t]=mn
 then begin
       find:=t;
       break;
      end;
end;
begin
 readln(n);
 for t:=1 to n do
 begin
  readln(name[t]);
  money[t]:=0;
 end;
for i:=1 to n do
 begin
  readln(s);
  readln(x,k);
  ren:=find(s);
  for j:=1 to k do
  begin
   readln(str);
   g:=find(str);
   money[g]:=money[g]+(x div k);
   money[ren]:=money[ren]-(x div k);
  end;
 end;
 for i:=1 to n do
 writeln(name[i],' ',money[i]);
end.



