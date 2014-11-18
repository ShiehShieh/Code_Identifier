var
  s,s1,s2,s3:string;
  uk:char;
  i,j,a,b,c,d,k:integer;
begin
  readln(s);
  i:=pos('=',s);
  s1:=copy(s,1,i-1);
  s2:=copy(s,i+1,length(s)-i);
  if s1[1]in['0'..'9','a'..'z','A'..'Z']then insert('+',s1,1);
  if s2[1]in['0'..'9','a'..'z','A'..'Z']then insert('+',s2,1);
  for i:=1 to length(s)do
    if s[i]in['A'..'Z','a'..'z']
    then  begin
            uk:=s[i];
            break;
          end;
  for i:=1 to length(s1)do
    if (s1[i-1]in['+','-'])and(s1[i]=uk)
      then insert('1',s1,i);
  for i:=1 to length(s2)do
    if (s2[i-1]in['+','-'])and(s2[i]=uk)
      then insert('1',s2,i);
  if pos(uk,s1)=0 then insert('+0'+uk,s1,1);
  if pos(uk,s2)=0 then insert('+0'+uk,s2,1);
  a:=0;b:=0;
  for i:=1 to length(s1)do
    begin
      if s1[i]=uk
      then  begin
              j:=i-1;
              while not(s1[j] in['+','-']) do dec(j);
              s3:=copy(s1,j,i-j);
              val(s3,c);
              inc(a,c);
              delete(s1,j,i-j+1);
              for k:=j to i do insert(' ',s1,k);
          end;
      if s1[i]in['+','-']
      then  begin
              j:=i+1;
              while (s1[j]in['0'..'9'])do inc(j);
              if s1[j]<>uk then  begin
              dec(j);
              s3:=copy(s1,i,j-i+1);
              val(s3,d);
              inc(b,d);                end;
            end;
    end;
  for i:=1 to length(s2)do
  begin
    if s2[i]=uk
    then  begin
            j:=i-1;
            while not(s2[j] in['+','-']) do dec(j);
            s3:=copy(s2,j,i-j);
            val(s3,c);
            inc(a,-c);
            delete(s2,j,i-j+1);
            for k:=j to i do insert(' ',s2,k);
          end;
    if s2[i]in['+','-']
      then  begin
              j:=i+1;
              while s2[j]in['0'..'9']do inc(j);
              if s2[j]<>uk then  begin
              dec(j);
              s3:=copy(s2,i,j-i+1);
              val(s3,d);
              inc(b,-d);                       end;
            end;
  end;
  write(uk,'=',b/(-a):0:3);
  readln;
end.
