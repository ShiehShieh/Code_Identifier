program nerve(input,output);
var
 flag:boolean;
 i,j,k,l,s,t,n,p,z :longint;
 u,c,link1:array[1..200]of longint;
 link:array[1..255,1..255]of longint;
begin
read(n,p);
for i:=1 to n do
  begin
   read(c[i],u[i]);
  end;
for i:=1 to p do
  begin
     read(s,t);
     read(link[s,t]);
     link1[s]:=1;
  end;
 for i:=n downto 1 do
    begin
      if c[i]=1 then
        break;
    end;
  z:=i+1;

 for i:=z to n do
    begin

          for k:=1 to i do
            begin

              if c[k]<>0 then
              c[i]:=c[i]+link[k,i]*c[k];
            end;
          c[i]:=c[i]-u[i];
       if c[i]<=0 then
         c[i]:=0;
    end;


 flag:=false;
 for i:=1 to n do
    begin
      if link1[i]=0 then
        begin
          if c[i]<>0 then
           begin
            writeln(i,' ',c[i]);
            flag:=true;
          end;
end;
 end;
if flag=false then
  write('NULL');
end.

