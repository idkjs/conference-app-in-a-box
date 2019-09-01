open ReactNative;
open DiscussionStyle;

type comment = {
  .
  "id": option(string),
  "talkId": option(string),
  "message": option(string),
  "createdAt": option(string),
  "createdBy": option(string),
  "deviceId": option(string),
  // "__typename": string,
};
module CreateComment = [%graphql
  {|
  mutation CreateComment($input: CreateCommentInput!) {
      createComment(input: $input) {
        id
        talkId
        message
        createdAt
        createdBy
        deviceId
      }
    }
  |}
];

module CreateCommentMutation = ReasonApollo.CreateMutation(CreateComment);

/** we need this to get at and work with the response to the mutation. We are taking the returned message item and appending it to the comments array showing in the browser */
type res = ReasonApolloTypes.executionResponse(CreateComment.t);
let dataComment =
    (
      ~message: option(string),
      ~createdAt: option(string),
      ~createdBy: option(string),
    )
    : ListCommentsQuery.item => {
  "message": message,
  "createdAt": createdAt,
  "createdBy": createdBy,
};
[@react.component]
let make = (~input, ~handleChangeText, ~handleSetComments, ~message) => {
  <CreateCommentMutation>
    ...{(mutate, _) =>
      <View>
        <TextInput
          value=message
          onChangeText={value => handleChangeText(_ => value)}
          style=styles##input
          onSubmitEditing={_ => {
            let newComment = CreateComment.make(~input, ());
            Js.Promise.(
              mutate(
                ~variables=newComment##variables,
                ~refetchQueries=[|"listCommentsByTalkIdQuery"|],
                (),
              )
              |> then_((response: res) => {
                   switch (response) {
                   | Errors(_errors) => Js.log("Error")
                   | EmptyResponse => Js.log("Empty")
                   | Data(data) =>
                     let createdAt =
                       [%get_in data##createComment#??createdAt]
                       ->Belt.Option.getWithDefault("");
                     let createdBy =
                       [%get_in data##createComment#??createdBy]
                       ->Belt.Option.getWithDefault("");
                     let message =
                       [%get_in data##createComment#??message]
                       ->Belt.Option.getWithDefault("");
                     let newItem =
                       dataComment(
                         ~message=Some(message),
                         ~createdAt=Some(createdAt),
                         ~createdBy=Some(createdBy),
                       );
                      /** this is basically a hand written cache update. */
                     handleSetComments(newItem);
                     handleChangeText(_ => "");
                   };
                   resolve(response);
                 })
              |> ignore
            );
          }}
          autoCapitalize=`none
          placeholder="Discuss this talk."
          autoCorrect=false
        />
        <Button
          title="Send"
          onPress={_ => {
            let newComment = CreateComment.make(~input, ());
            // Js.log2("BUTTON_NEW_COMMENT: ", newComment);
            Js.Promise.(
              mutate(
                ~variables=newComment##variables,
                ~refetchQueries=[|"listCommentsByTalkIdQuery"|],
                (),
              )
              |> then_((response: res) => {
                   switch (response) {
                   | Errors(_errors) => Js.log("Error")
                   | EmptyResponse => Js.log("Empty")
                   | Data(data) =>
                    //  Js.log2("BUTTON_DATA: ", data##createComment);
                     let createdAt =
                       [%get_in data##createComment#??createdAt]
                       ->Belt.Option.getWithDefault("");
                     let createdBy =
                       [%get_in data##createComment#??createdBy]
                       ->Belt.Option.getWithDefault("");
                     let message =
                       [%get_in data##createComment#??message]
                       ->Belt.Option.getWithDefault("");
                     let newItem =
                       dataComment(
                         ~message=Some(message),
                         ~createdAt=Some(createdAt),
                         ~createdBy=Some(createdBy),
                       );
                     handleSetComments(newItem);
                     handleChangeText(_ => "");
                   };
                   resolve(response);
                 })
              |> ignore
            );
          }}
        />
      </View>
    }
  </CreateCommentMutation>;
};