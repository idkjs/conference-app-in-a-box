open ReactNative;
/* Create a GraphQL Query by using the graphql_ppx */
type item = {
  .
  "message": option(string),
  "createdAt": option(string),
  "createdBy": option(string),
};
type items = array(item);

module QueryConfig = [%graphql
  {|
query listCommentsByTalkId($talkId: ID!) {
  listCommentsByTalkId(talkId: $talkId) {
    items {
      message
      createdAt
      createdBy
    }
  }
}
  |}
];
module ListCommentsByTalkIdQuery =
  ReasonApollo.CreateQuery(QueryConfig);
let talkId = "d4447477-20fc-4a48-a97f-edfb486b5d6a";

[@react.component]
let make = (~children) => {
  let listCommentsByTalkIdQuery =
    QueryConfig.make(
      ~talkId="d4447477-20fc-4a48-a97f-edfb486b5d6a",
      (),
    );
  let variables = listCommentsByTalkIdQuery##variables;

  <ListCommentsByTalkIdQuery variables>
    ...{({result}) =>
      switch (result) {
      | Loading => <Text> {ReasonReact.string("Loading")} </Text>
      | Error(error) => <Text> {ReasonReact.string(error##message)} </Text>
      | Data(response) =>
        let items =
          [%get_in response##listCommentsByTalkId#??items]
          ->Belt.Option.getWithDefault([||])->Belt.Array.keepMap(x=>x);
        children(items);
      }
    }
  </ListCommentsByTalkIdQuery>;
};