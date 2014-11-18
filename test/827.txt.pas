program JamesBend;
var
 sum,i,m,n,k,j,p:integer;
 s:string;
 use:array[1..200]of boolean;
 a:array[1..200,1..200]of boolean;
procedure chuli(w:string;j:integer);
var
 i1,s2,ss,i:integer;
begin
  i:=0;
  repeat
   inc(i);
   if (w[i]<>' ')and (w[i]<>'0') then
                  begin
                   i1:=i;
                   repeat
                   inc(i1);
                   until (w[i1]=' ');
                   dec(i1);
                   ss:=0;
                   for s2:=i to i1 do
                      ss:=ss*10+ord(w[s2])-48;

                   a[ss,j]:=true;
                   i:=i1+1;
                 end;
  until i=length(w);
end;
begin

 readln(n);
 fillchar(a,sizeof(a),false);
 fillchar(use,sizeof(use),false);
 for i:=1 to n do
  begin
   readln(s);
    chuli(s,i);
  end;
 for i:=1 to n do
  for j:=1 to n do
   for k:=1 to n do
    if a[j,i] and a[k,i] then
     a[j,k]:=true;


       for i:=1 to n do

           if not  use[i] then
                         begin
                          inc(sum);
                          for j:=i+1 to n do
                           if a[i,j] then use[j]:=true;
                         end;


 writeln(sum);


end.

