type a;
[@bs.module "aws-amplify"] external auth: a = "Auth";

type s;
[@bs.send] external currentSession: a => s = "currentUserCredentials";
let fee = currentSession(auth);

type t = {
  graphqlEndpoint: string,
  region: string,
  authenticationType: string,
  jwtToken: s,
};

let appSyncConfig = {
  graphqlEndpoint: "https://b2sszbbervfopf3ze3enjk35vi.appsync-api.eu-west-1.amazonaws.com/graphql",
  region: "eu-west-1",
  authenticationType: "AMAZON_COGNITO_USER_POOLS",
  jwtToken: fee,
};