# Builder stage
FROM maven:3.9.6-eclipse-temurin-21-alpine as builder

RUN apk add --no-cache curl
RUN apk add --no-cache nodejs npm
WORKDIR /src/worker
COPY . .

RUN mvn -e clean package

RUN touch target/worker-jar-with-dependencies.jar

# Final stage
FROM eclipse-temurin:21-jre-alpine

WORKDIR /app

COPY --from=builder /src/worker/target/worker-jar-with-dependencies.jar .

CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]
