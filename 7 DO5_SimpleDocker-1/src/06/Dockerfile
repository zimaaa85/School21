FROM nginx
USER root
WORKDIR /home/
COPY ./server.c /home/server.c
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./run.sh /home/run.sh
RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev \
    && chmod 777 /home/run.sh \
    && rm -rf /var/lib/apt/lists \    
    && service nginx start \
    #&& useradd dockle \
    && chown -R dockle:dockle /etc/nginx/nginx.conf \
    && chown -R dockle:dockle /var/cache/nginx \
    && chown -R dockle:dockle /home \
    && touch /var/run/nginx.pid \
    && chown -R dockle:dockle /var/run/nginx.pid

USER dockle

ENTRYPOINT ["sh", "/home/run.sh"]
HEALTHCHECK --interval=30s --timeout=30s --start-period=5s --retries=3 CMD curl -f http://localhost:80 || exit 1
