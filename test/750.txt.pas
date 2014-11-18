var i,j,l,o,p,y,k,u,q,w:longint;
    m,min:real;
    begin
      read(l,o,p,y,k);
      min:=32767;
      for i:=0 to 10 do
        for j:=0 to 10 do
          for u:=0 to 10 do
            for q:=0 to 10 do
            if (i+j+u+q<=l)then
              begin
                w:=(10+q)*k;
                m:=(20-i*2)*o+(100-j*7)*p/w*2+(100-u*9)*y/w;
                if m<min then min:=m;
              end;
              writeln(min:0:3);
        end.
